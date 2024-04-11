#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int a[6];
int main() {
    for (int i=0;i<6;i++){
        char ch;
        cin>>ch;
        a[i]=ch-'0';
    }
    if (a[0]+a[1]+a[2]>a[3]+a[4]+a[5]){
        swap(a[0],a[3]);
        swap(a[1],a[4]);
        swap(a[2],a[5]);
    }
    int x=a[3]+a[4]+a[5]-a[0]-a[1]-a[2],ans=0;
    int l=0,r=5;
    sort(a,a+3);
    sort(a+3,a+6);
    while (x>0){
        ans++;
        if (l<3 && 9-a[l]>=a[r]){
            x-=9-a[l];
            l++;
        }
        else {
            x-=a[r];
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}