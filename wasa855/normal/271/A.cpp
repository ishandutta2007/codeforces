#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    while(1)
    {
        m++;
        if(m/1%10!=m/10%10 && m/1%10!=m/100%10 && m/1%10!=m/1000%10 && m/10%10!=m/1000%10 && m/10%10!=m/100%10&&m/100%10!=m/1000%10)
        {
            break;
        }
    }
    cout<<m<<endl;
    return 0;
}
///////////////////////
///////////adscomilufsdhmkjtds