#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int N, T, i, j;
string s;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        cin >> s;
        int prev = 0;
        for(i=0;i<N;i++){
            for(j=1;j>=0;j--){
                if(j+s[i]-'0'!=prev){
                    printf("%d",j);
                    prev = j+s[i]-'0';
                    break;
                }
            }
        }
        printf("\n");
    }
}