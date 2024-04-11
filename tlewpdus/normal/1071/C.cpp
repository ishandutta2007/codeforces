#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int arr[100100];
int trr[] = {7,21,73,273};
int val[20];
int pcnt[1<<25];
int D[520];
int via[520];
int INF = 1e9;

vector<int> vec;
int solve(int n, int bit) {
    int i, j;
    for (i=0;i<4;i++) {
        for (j=0;(trr[i]<<j)<(1<<n);j++) vec.push_back(trr[i]<<j);
    }
    int mini = vec.size()+1, t = -1;
    for (i=0;i<(1<<vec.size());i++) {
        int x = 0, y = 0;
        for (j=0;j<vec.size();j++) if (i>>j&1) {
            x ^= vec[j];
            y++;
        }
        if (x==bit&&mini>y) {
            mini=y;
            t=i;
        }
    }
    return t;
}

void print(int bia, int ans) {
    int i, j;
    for (i=0;i<vec.size();i++) {
        if (ans>>i&1) {
            int v = vec[i];
            for (j=0;j<9;j++) {
                if (v>>j&1) printf("%d ",j+bia+1);
            }
            printf("\n");
        }
    }
}

struct str {
    int a, b, c;
};

vector<str> tec;

bool ps(int a, int b) {
    if (a+2*b>=n) return 0;
    tec.push_back({a+1,a+b+1,a+2*b+1});
    arr[a]^=1;
    arr[a+b]^=1;
    arr[a+2*b]^=1;
    return 1;
}

int main() {
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    if (n<=9) {
        int x = 0;
        for (i=n-1;i>=0;i--){
            x=x*2+arr[i];
        }
        int ans = solve(n,x);
        if (ans<0) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        int c = 0;
        for (i=0;i<vec.size();i++) if (ans>>i&1) c++;
        printf("%d\n",c);
        print(0,ans);
        return 0;
    }
    printf("YES\n");
    for (i=0;i+2<n;i++) {
        if (!arr[i]) continue;
        if (arr[i+1]==0) {
            if (arr[i+2]==0) {
                if (!ps(i,3)) break;
            }
            else {
                if (!ps(i,2)) break;
            }
        }
        else {
            if (arr[i+2]==0) {
                if (i+6>=n) break;
                if (arr[i+3]==0) {
                    if (arr[i+4]==0&&arr[i+5]==1) {
                        ps(i+1,2);
                        if (!ps(i,3)) break;
                    }
                    else {
                        if (!ps(i+1,3)) break;
                        if (arr[i+4]==1) {
                            if (!ps(i,4)) break;
                        }
                        else if (arr[i+5]==1) {
                            if (!ps(i,5)) {
                                ps(i,1);
                                ps(i+1,1);
                            }
                        }
                        else {
                            if (!ps(i,6)) {
                                ps(i,2);
                                if (!ps(i+2,2)) break;
                            }
                        }
                    }
                }
                else {
                    if (arr[i+4]==1&&arr[i+5]==0) {
                        if (!ps(i,3)) break;
                        if (!ps(i+1,3)) break;
                    }
                    else {
                        ps(i+1,2);
                        if (arr[i+4]==1) {
                            if (!ps(i,4)) break;
                        }
                        else if (arr[i+5]==1) {
                            if (!ps(i,5)) {
                                ps(i,1);
                                ps(i+1,1);
                            }
                        }
                        else {
                            if (!ps(i,6)) {
                                ps(i,2);
                                if (!ps(i+2,2)) break;
                            }
                        }
                    }
                }
            }
            else {
                if (!ps(i,1)) break;
            }
        }
    }
    int t = i;
    int x = 0;
    for (i=n-1;i>n-10;i--){
        x=x*2+arr[i];
    }
    int ans = solve(9,x);
    int c = 0;
    for (i=0;i<vec.size();i++) if (ans>>i&1) c++;
    printf("%d\n",tec.size()+c);
    for (str &s : tec) printf("%d %d %d\n",s.a,s.b,s.c);
    print(n-9,ans);

    return 0;
}