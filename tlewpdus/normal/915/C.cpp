#include <bits/stdc++.h>

using namespace std;

int n, m;
char str[22], ttr[22];
int arr[22], brr[22];
int ans[22];
int act[11];

bool bt(int id, bool fl) {
    int i;
    if (id==n) {
        for (i=0;i<n;i++) printf("%d",ans[i]);
        printf("\n");
        return true;
    }
    if (fl) {
        for (i=brr[id];i>=0;i--) if (act[i]) break;
        int n = i;
        if (n<0) return false;
        if (n==brr[id]) {
            act[n]--;
            ans[id] = n;
            bool rt = bt(id+1,fl);
            act[n]++;
            if (rt) return true;
            for (i=n-1;i>=0;i--) if (act[i]) break;
            n = i;
            if (n<0) return false;
        }
        act[n]--;
        ans[id] = n;
        bt(id+1,false);
    }
    else {
        for (i=9;i>=0;i--) if (act[i])break;
        ans[id] = i;
        act[i]--;
        bt(id+1,0);
        act[i]++;
    }
    return true;
}

int main() {
    int i;

    scanf(" %s",str); scanf(" %s",ttr);
    n = strlen(str); m = strlen(ttr);
    for (i=0;i<n;i++) arr[i] = str[i]-'0';
    for (i=0;i<n;i++) act[arr[i]]++;
    for (i=0;i<m;i++) brr[i] = ttr[i]-'0';
    if (n<m) {
        sort(arr,arr+n);
        for (i=n-1;i>=0;i--) printf("%d",arr[i]);
        printf("\n");
        return 0;
    }
    bt(0,1);

    return 0;
}