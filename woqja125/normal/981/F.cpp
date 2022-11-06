#include<cstdio>
#include<algorithm>
using namespace std;
int a[200001];
int b[600001];
int n, L;
bool chk(int d){
    if(d*2 >= L) return true;
    int l=0, r=0;
    for(l=0; b[l] < a[0]-d; l++);
    for(r=3*n-1; b[r] > a[0]+d; r--);
    for(int i=1; i<n; i++){
        l++; r++;
        for(; b[l] < a[i]-d; l++);
        for(; b[r] > a[i]+d; r--);
    }
    return l<=r;
}
int main(){
    scanf("%d%d", &n, &L);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    for(int i=0; i<n; i++) scanf("%d", b+n+i);
    for(int i=0; i<n; i++){
        b[i] = b[i+n] - L;
        b[i+2*n] = b[i+n] + L;
    }
    sort(a, a+n);   sort(b, b+3*n);
    int f = 0, r = L/2+1;
    while(f<r){
        int m = (f+r)/2;
        if(chk(m)) r = m;
        else f = m+1;
    }
    printf("%d\n", f);
    return 0;
}