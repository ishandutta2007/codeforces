%:pragma GCC optimize(4)
#include <cstdio>
#include <set>
#include <cstring>
#include <utility>

static const  int MAX = 100005;
typedef long long ll;

typedef ::std::pair<int,int> pii;

using namespace std;

static const int BSIZE = 319;


int previous[MAX];
int nextOccur[MAX];
int a[MAX];
int mark[MAX];
set<int> occ[MAX];

ll tree[325][325];

int Block[MAX];

// 2D Fenwick Tree implementation.
static inline int lbs(int x){return x & -x; }

// ok tested
void update(int x , int y , int val)
{
    if(!x || !y) return;
    x = Block[ x ];
    y = Block[ y ];
    for(int i = x; i <= 320; i += lbs(i)){
        for(int j = y; j <= 320; j += lbs(j)){
            tree[i][j] += val;
        }
    }
}

// ok tested
ll query(int x,int y){
    ll ans = 0;
    for(int i = x; i > 0; i -= lbs(i)){
        for(int j = y; j > 0; j -= lbs(j) ){
            ans += tree[i][j];
        }
    }
    return ans;
}

//ok tested
pii look_out(int elem,int ind)
{
    // it - indicated first element that GREATER than ind.
    set<int>::iterator it = occ[ elem ].upper_bound( ind );
    pii ans;
    if( it == occ[ elem ].end())
    {
        ans.first = 0;
    }else{
        ans.first = *it;
    }
    it--;
    if(it == occ[elem].begin())
    {
        ans.second=0;
    }
    else
    {
        it--;
        ans.second = *it;
    }
    return ans;
}

int n, nquery;

void ReadInit()
{
    scanf("%d%d", &n, &nquery);

    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) {
        scanf("%d",a+i);
        occ[ a[ i ] ].insert( i );
    }

    Block[ 0 ] = 0 ;

    for(int i = 1;i <= n; i++) {
        Block[ i ]= ( i - 1 ) / BSIZE + 1;
    }

    memset(mark, 0, sizeof(mark));

    for(int i = 1; i <= n; i++) {
        previous[i]=mark[a[i]];
        mark[a[i]]=i;
    }

    memset(mark, 0, sizeof(mark));

    for(int i = n; i >= 1 ; --i) {
        nextOccur[ i ] = mark[ a[ i ] ] ;
        mark[ a[ i ] ] = i;
    }

    // update the tree here
    for(int i = 1; i <= n;i++) {
        if ( nextOccur[i] > 0 )
            update(i, nextOccur[i], nextOccur[i ] - i);
    }
}

void update_ans(int pos, int val)
{
    int p,x;
    p  = pos; x = val;
    if( a[ p ] == x) return;

    int i = p;
    occ[x].insert(i);

    pii got = look_out(x,i);
    nextOccur[i] = got.first;
    previous[i] = got.second;
    if(nextOccur[i] > 0) {
        update(i,nextOccur[i],nextOccur[i]-i);
        previous[nextOccur[i]]=i;
    }
    if(previous[i] > 0) {
        update(previous[i],i,i-previous[i]);
        nextOccur[previous[i]]=i;
    }
    // subtract (nextOccur[i] - previous[i])
    update(previous[i],nextOccur[i], previous[i]-nextOccur[i]);

    got = look_out(a[p],i);
    if(got.first){
        update(i,got.first, i - got.first);
        previous[got.first]=got.second;
    }
    if(got.second){
        update(got.second, i, got.second - i);
        nextOccur[got.second]=got.first;
    }
    update(got.second, got.first, got.first - got.second);
    occ[ a[ p ] ].erase( i );
    a[ p ] = x;

}

ll query_ans(int l, int r)
{
    ll ans = 0;

    if( ( r - l ) <= 2 * BSIZE + 2 ) {
        for(int i=l;i<=r;i++) {
            if ( nextOccur[ i ] > 0 && nextOccur[i] <= r)
                ans += nextOccur[i] - i;
        }
        return ans;
    }

    int just_big = l/BSIZE;
    just_big *= BSIZE;
    just_big += 1;
    if(just_big<=l) just_big += BSIZE;

    int just_small = r/BSIZE;
    just_small *= BSIZE;
    if(just_small==r) just_small-=BSIZE;

    swap(just_big,just_small);

    ans =   query( Block[ just_big ], Block[just_big]) -
            query( Block[ just_small] - 1, Block[just_big]) -
            query( Block[ just_big], Block[just_small]-1) +
            query( Block[ just_small]-1,Block[just_small]-1);

    swap(just_big,just_small);

    for(int i=l;i<just_big;i++){
        if (nextOccur[i] >0 && nextOccur[i] <= r)
            ans += nextOccur[i] - i;
    }

    for(int i=just_small+1;i<=r;i++) {
        if (previous[i] >= just_big)
            ans += i - previous[i];
    }
    return ans;
}
int main()
{
    ReadInit();
    while(nquery--){
        int t, x, y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1){
            update_ans(x, y);
        }
        else {
            ll ans = query_ans(x, y);
            printf("%lld\n", ans);
        }
    }
}