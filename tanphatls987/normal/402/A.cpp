#include <iostream>

using namespace std;

int main()
{
    int k,a,b,v,cell;
    cin>>k>>a>>b>>v;
    /*if (a>(b+1)*v) cout<<(b+k-1)/k+(a-(b+1)*v+v-1)/v;else cout<<(((a+v-1)/v)+k-1)/k;*/
    cell=(b+k-2)/(k-1)+b;
    if (a>cell*v) cout<<(cell+k-1)/k+(a-cell*v+v-1)/v;else cout<<(((a+v-1)/v)+k-1)/k;
}