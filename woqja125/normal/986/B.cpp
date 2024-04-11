#include <cstdio>
int a[1000001];
int IT[5000001];
int b = 1;
int getsum(int f, int r){
    f += b; r+= b;
    int ans = 0;
    while(f<=r){
        if(f%2 == 1) ans += IT[f++];
        if(r%2 == 0) ans += IT[r--];
        f/=2; r/=2;
    }
    return ans;
}
void add(int x, int v){
    IT[x+=b] += v;
    while(x/=2) IT[x] += v;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    for(b=1; b<=n; b*=2);
    long long inv = 0;
    for(int i=1; i<=n; i++){
        inv = (inv + getsum(a[i]+1, n)) & 1;
        add(a[i], 1);
    }
    if(n%2 == 1) inv ^= 1;
    printf(inv?"Um_nik\n":"Petr\n");
    return 0;
}