#include <bits/stdc++.h>
using namespace std;
int main()
{
        int a, b, c, d, dragons;
        set<int> s;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &dragons);
        if(min({a,b,c,d})==1){
            printf("%d", dragons);
            return 0;
        }
        for(int i = 1; i <= dragons; i++) {
            if(i%a==0){
                s.insert(i);
                continue;
            }
            else if(i%b==0) {
                s.insert(i);
                continue;
            }
            else if(i%c==0)  {
                s.insert(i);
                continue;
            }
            else if(i%d==0) {
                s.insert(i);
                continue;
            }
        }
        int g = s.size();
        cout << g;
        return 0;
}