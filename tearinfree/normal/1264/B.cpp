#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int *v, int val) {
    for(int i=0;i<arr[1];i++) printf("%d %d ",v[1], v[0]);
    for(int i=0;i<arr[0]-arr[1];i++) printf("%d %d ",v[2], v[0]);
    for(int i=0;i<arr[3];i++) printf("%d %d ",v[2], v[3]);
    if(val) printf("%d",v[2]);
}
int main() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(d>c+1 || a>b+1 || (d==c+1 && (a||b)) || (a==b+1 && (c||d))) {
        puts("NO");
        return 0;
    }
    
    if(d==c+1) {
        puts("YES");
        for(int i=0;i<c;i++) printf("3 2 ");
        puts("3");
        return 0;
    } else if(a==b+1) {
        puts("YES");
        for(int i=0;i<b;i++) printf("0 1 ");
        puts("0");
        return 0;
    } else {
        int val = (c-d) - (b-a);
        if(abs(val) > 1) {
            puts("NO");
            return 0;
        } else {
            puts("YES");

            int arr[4] = {b,a,c,d}, v[4] = {1, 0, 2, 3};
            if(val == -1) {
                for(int i=0;i<2;i++) swap(arr[i],arr[i+2]), swap(v[i],v[i+2]);
                val = 1;
            }
            solve(arr, v, val);
        }
    }
    return 0;
}