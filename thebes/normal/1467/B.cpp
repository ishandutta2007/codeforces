#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int T, N, i, arr[MN], x, suf[MN];

inline int hm(int idx){
    if(idx<=1||idx>=N) return 0;
    if(arr[idx]>arr[idx-1]&&arr[idx]>arr[idx+1]) return 1;
    else if(arr[idx]<arr[idx-1]&&arr[idx]<arr[idx+1]) return 1;
    else return 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%d",&arr[i]);
        suf[N+2] = suf[N+1] = suf[N] = 0;
        for(i=N;i>=1;i--){
            suf[i] = suf[i+1]+hm(i);
        }
        int pref = 0;
        int ans = N+1;
        arr[0] = arr[1], arr[N+1] = arr[N];
        for(i=1;i<=N;i++){
            pref += hm(i-2);
            int tmp = arr[i];
            arr[i] = arr[i-1];
            ans = min(ans, hm(i-1)+hm(i)+hm(i+1)+pref+suf[i+2]);
            arr[i] = arr[i+1];
            ans = min(ans, hm(i-1)+hm(i)+hm(i+1)+pref+suf[i+2]);
            arr[i] = tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}