#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,mmx,popcnt")

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

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

int less(const int, const int)__attribute__((hot));
int
less(const int a, const int b){
	return a < b;
}

map_t * tot;

int64_t solve(map_node * v){
	if(!v)return 0;
	long long ans = 0;
	ans += v->value * 1ll * (v->value-1);
	int mask = v->key;
	for(int pos = 0; pos < 27; pos++){
		int nxt = mask^(1<<pos);
		map_node * u = map_find(tot, nxt);
		if(u)ans += v->value * 1ll * u->value;
	}
	ans += solve(v->l);
	ans += solve(v->r);
	return ans;
}

int
main(){
	tot = create_map(less);
	int n;
	scanf("%d\n", &n);
	char * s = malloc(1000006);
	for(int i = 0; i < n; i++){
		gets(s);
		char * t = s;
		int mask = 0;
		while(*t){
			mask ^= 1<<(*t - 'a');
			++t;
		}
		map_node * v = map_find(tot, mask);
		if (v)
			++v->value;
		else
			map_insert(tot, mask, 1);
	}
	printf("%lld", solve(tot->root)/2);
	return 0;
}