#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, i, j, x, p[MN], cur, mrk[MN], cnt;

inline void rem(int x){
    if(x<=n){
        printf("B %d\n",x);
        fflush(stdout); cnt++;
        for(int i=x;i<=n;i+=x){
            if(!mrk[i]) cur--;
            mrk[i] = 1;
        }
        int r; scanf("%d",&r);
    }
}

inline int qu(int x){
    if(x<=n){
        printf("A %d\n",x);
        fflush(stdout); cnt++;
        int r; scanf("%d",&r);
        return r;
        /*int res = 0;
        for(int i=x;i<=n;i+=x){
            if(!mrk[i]||i==X) res++;
        }
        return res;*/
    }
}

inline int chk(int x){
    int res = 0;
    for(int i=x;i<=n;i+=x){
        if(!mrk[i]) res++;
    }
    return res;
}

inline void ans(int x){
    printf("C %d\n",x);
    fflush(stdout);
}

vector<int> a, b, c, d;

void rec(int l,int r){
    if(l>r) return;
    int mid = (l+r)>>1;
    for(int i=l;i<=mid;i++){
        rem(d[i]);
    }
    if(qu(1)!=cur){
        for(int i=l;i<=mid;i++){
            if(qu(x*d[i])){
                x *= d[i];
                break;
            }
        }
    }
    else{
        rec(mid+1,r);
    }
}

int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(p[i]) continue;
		if(i<=317) a.push_back(i);
		else if(i<50000) b.push_back(i);
		else c.push_back(i);
		for(j=i;j<=n;j+=i)
			p[j] = 1;
	}
	cur = n;
	for(auto v : c){
        rem(v);
	}
	if(qu(1)!=cur){
        for(auto v : c){
            if(qu(v)){
                ans(v);
                return 0;
            }
        }
	}
	x = 1;
	for(auto v : a){
        rem(v);
	}
	for(auto v : a){
        while(1LL*x*v<=n&&qu(x*v)){
            x *= v;
        }
	}
	for(auto v : b){
        if(1LL*v*x<=n) d.push_back(v);
	}
	if(x!=1){
        for(auto v : b){
            if(qu(v)!=chk(v)){
                x *= v;
                break;
            }
        }
	}
	else if(d.size()) rec(0,(int)d.size()-1);
	printf("C %d\n",x);
	fflush(stdout);
	//printf("QUERIES: %d\n",cnt);
	return 0;
}