#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,mmx,popcnt")

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<ctype.h>

// TEMPLATE BEGIN

#define FASTIO_BUF_SZ  (1<<12)
static char in_buf[FASTIO_BUF_SZ];
static size_t in_buf_ptr = 0, in_buf_len = 0;
static char out_buf[FASTIO_BUF_SZ];
static size_t out_buf_ptr = 0;

static inline char read_char(){
	if(__builtin_expect(in_buf_ptr == in_buf_len, 0)){
		in_buf_ptr = 0;
		in_buf_len = fread(in_buf, 1, FASTIO_BUF_SZ, stdin);
	}
	return in_buf[in_buf_ptr++];
}

static inline void flush(){
	fwrite(out_buf, 1, out_buf_ptr, stdout);
	out_buf_ptr = 0;
}

static inline void write_char(char c){
	if(__builtin_expect(out_buf_ptr == FASTIO_BUF_SZ, 0))
		flush();
	out_buf[out_buf_ptr++] = c;
}

static char write_tmp[FASTIO_BUF_SZ];

#define rint(x) for(int rintkektmp = 0; rintkektmp < 1; rintkektmp++){\
	x = 0;\
	char c = 0;\
	while(c != '-' && !isdigit(c))\
		c = read_char();\
	int neg = 0;\
	if(c == '-'){neg = 1; c = read_char();}\
	while(isdigit(c)){\
		x = x*10 + (c - '0');\
		c = read_char();\
	}\
	if(neg)x = -x;\
	}

#define wint(x) for(int wintkektmp = 0; wintkektmp < 1; wintkektmp++){\
	if(x < 0){write_char('-'); x = -x;}\
	int pos = 0;\
	if(!x)write_tmp[pos++] = '0';\
	while(x){\
		write_tmp[pos++] = '0' + x%10;\
		x /= 10;\
	}\
	for(int i = pos - 1; i >= 0; i--)write_char(write_tmp[i]);\
	}

typedef struct map_node map_node;

#define MAP_KEY_TYPE int
#define MAP_VALUE_TYPE int

struct map_node{
	MAP_KEY_TYPE key;
	MAP_VALUE_TYPE value;
	map_node *l, *r;
	int32_t h;
};

map_node * _avl_create_node()__attribute__((hot));
map_node *
_avl_create_node(){
	map_node * v = (map_node *)malloc(sizeof(map_node));
	v->l = v->r = NULL;
	v->h = 1;
	return v;
}

int32_t _avl_h(map_node*)__attribute__((hot));
int32_t
_avl_h(map_node * v){
	return v ? v->h : 0;
}

void _avl_upd_h(map_node*)__attribute__((hot));
void
_avl_upd_h(map_node * v){
	if (!v)
		return;
	v->h = _avl_h(v->l) > _avl_h(v->r) ? _avl_h(v->l) : _avl_h(v->r);
	++v->h;
}

int32_t _avl_balance(map_node*)__attribute__((hot));
int32_t
_avl_balance(map_node * v){
	return v ? _avl_h(v->l) - _avl_h(v->r) : 0;
}

map_node * _avl_right_rotate(map_node*)__attribute__((hot));
map_node *
_avl_right_rotate(map_node * v){
	map_node * u = v->l;
	v->l = u->r;
	u->r = v;
	_avl_upd_h(v);
	_avl_upd_h(u);
	return u;
}

map_node * _avl_left_rotate(map_node*)__attribute__((hot));
map_node *
_avl_left_rotate(map_node * v){
	map_node * u = v->r;
	v->r = u->l;
	u->l = v;
	_avl_upd_h(v);
	_avl_upd_h(u);
	return u;
}

map_node * _avl_insert(map_node*, MAP_KEY_TYPE, MAP_VALUE_TYPE, int(*)(const MAP_KEY_TYPE, const MAP_KEY_TYPE))__attribute__((hot));
map_node *
_avl_insert(map_node * v, MAP_KEY_TYPE key, MAP_VALUE_TYPE value, int (*comp)(const MAP_KEY_TYPE, const MAP_KEY_TYPE)){
	if (!v) {
		v = _avl_create_node();
		v->key = key;
		v->value = value;
		return v;
	}
	if (comp(v->key, key)) {
		v->r = _avl_insert(v->r, key, value, comp);
	} else if (comp(key, v->key)){
		v->l = _avl_insert(v->l, key, value, comp);
	}
	else return v;
	_avl_upd_h(v);
	int32_t bal = _avl_balance(v);
	if (bal < -1 && _avl_h(v->r->l) > _avl_h(v->r->r)) {
		v->r = _avl_right_rotate(v->r);
		return _avl_left_rotate(v);
	}
	if (bal > 1 && _avl_h(v->l->r) > _avl_h(v->l->l)) {
		v->l = _avl_left_rotate(v->l);
		return _avl_right_rotate(v);
	}
	if (bal < -1)
		return _avl_left_rotate(v);
	if (bal > 1)
		return _avl_right_rotate(v);
	return v;
}

map_node * _avl_erase(map_node*, MAP_KEY_TYPE, int(*)(const MAP_KEY_TYPE, const MAP_KEY_TYPE))__attribute__((hot));
map_node *
_avl_erase(map_node * v, MAP_KEY_TYPE key, int (*comp)(const MAP_KEY_TYPE, const MAP_KEY_TYPE)){
	if (!v) {
		return NULL;
	}
	if (comp(key, v->key)) {
		v->l = _avl_erase(v->l, key, comp);
	} else if (comp(v->key, key)) {
		v->r = _avl_erase(v->r, key, comp);
	} else {
		if (!v->l && !v->r) {
			free(v);
			return NULL;
		}
		if (!v->l) {
			map_node * u = v->r;
			free(v);
			return u;
		}
		if (!v->r) {
			map_node * u = v->l;
			free(v);
			return u;
		}
		map_node * u = v->r;
		while (u->l)
			u = u->l;
		v->key = u->key;
		v->value = u->value;
		v->r = _avl_erase(v->r, u->key, comp);
	}
	_avl_upd_h(v);	
	int32_t bal = _avl_balance(v);
	if (bal < -1 && _avl_h(v->r->l) > _avl_h(v->r->r)) {
		v->r = _avl_right_rotate(v->r);
		return _avl_left_rotate(v);
	}
	if (bal > 1 && _avl_h(v->l->r) > _avl_h(v->l->l)) {
		v->l = _avl_left_rotate(v->l);
		return _avl_right_rotate(v);
	}
	if (bal < -1)
		return _avl_left_rotate(v);
	if (bal > 1)
		return _avl_right_rotate(v);
	return v;
}

map_node * _avl_find(map_node*, MAP_KEY_TYPE, int(*)(const MAP_KEY_TYPE, const MAP_KEY_TYPE))__attribute__((hot));
map_node *
_avl_find(map_node * root, MAP_KEY_TYPE key, int (*comp)(const MAP_KEY_TYPE, const MAP_KEY_TYPE)){
	if (!root)
		return NULL;
	if(comp(root->key, key))
		return _avl_find(root->r, key, comp);
	else if(comp(key, root->key))
		return _avl_find(root->l, key, comp);
	else return root;
}

typedef struct map_t map_t;

struct map_t{
	map_node * root;
	int (*comp)(const MAP_KEY_TYPE, const MAP_KEY_TYPE);
};

map_t * create_map(int(*)(const MAP_KEY_TYPE, const MAP_KEY_TYPE))__attribute__((hot));
map_t *
create_map(int (*comp)(const MAP_KEY_TYPE, const MAP_KEY_TYPE)){
	map_t * result = (map_t *)malloc(sizeof(map_t));
	result->root = NULL;
	result->comp = comp;
	return result;
}

map_node * map_find(map_t*, MAP_KEY_TYPE)__attribute__((hot));
map_node *
map_find(map_t * map, MAP_KEY_TYPE key){
	map_node * v = _avl_find(map->root, key, map->comp);
	return v;
}

void map_insert(map_t*, MAP_KEY_TYPE, MAP_VALUE_TYPE)__attribute__((hot));
void
map_insert(map_t * map, MAP_KEY_TYPE key, MAP_VALUE_TYPE value){
	map->root = _avl_insert(map->root, key, value, map->comp);
}

void map_erase(map_t*, MAP_KEY_TYPE)__attribute__((hot));
void
map_erase(map_t * map, MAP_KEY_TYPE key){
	map->root = _avl_erase(map->root, key, map->comp);
}

// TEMPLATE END
int lessu(const MAP_KEY_TYPE a, const MAP_KEY_TYPE b){
	return a < b;
}

uint32_t * keys;
int * values;
int ptr = 0;

void solve(map_node * v){
	if (v == NULL)
		return;
	uint32_t x = v->key;
	int cx = v->value;
	keys[ptr] = x;
	values[ptr] = cx;
	++ptr;
	solve(v->l);
	solve(v->r);
}

int main(){
	map_t * cnt = create_map(lessu);
	int n, k;
	rint(n);
	rint(k);
	uint32_t curr = 0;
	for(int i = 0; i < n; i++){
		uint32_t a;
		rint(a);
		curr ^= a;
		map_node * v = map_find(cnt, curr);
		if (v == NULL){
			map_insert(cnt, curr, 1);
		}
		else
			++v->value;
	}
	map_t * used = create_map(lessu);
	uint32_t kek = ((uint32_t)1)<<k;
	--kek;
	int64_t best = 0;
	best = n * 1ll * (n - 1)/2 + n;
	keys = malloc((2 + n) * sizeof(uint32_t));
	values = malloc((2 + n) * sizeof(int));
	solve(cnt->root);
	srand(time(0));
	for(int i = 0; i < ptr; i++){
		uint32_t x = keys[i];
		int cx = values[i];
		if (map_find(used, x) != NULL)
			continue;
		map_insert(used, kek^x, 1);
		if(x == 0 || x == kek)continue;
		map_node * tmp = map_find(cnt, kek^x);
		if(tmp != NULL)
			cx += tmp->value;
		int l = cx/2, r = cx - l;
		best -= l * 1ll * (l-1)/2 + r * 1ll * (r - 1)/2;
	}
	map_node * tmp = map_find(cnt, 0);
	int cx = 0;
	if(tmp)cx += tmp->value;
	tmp = map_find(cnt, kek);
	if(tmp)cx += tmp->value;
	int l = cx/2, r = cx - l;
	l += 1;
	best -= l * 1ll * (l - 1)/2 + r * 1ll * (r - 1)/2;
	wint(best);
	flush();
	return 0;
}