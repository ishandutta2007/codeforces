#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct med
{
    int kg;
    int kol;
};
bool operator < (med a, med b)
{
if(a.kg<b.kg)
{
    return true;
}
return false;
}
med mas[150];
int n, k;
int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> k;
    for (int q=0; q<n; q++)
    {
        cin >> mas[q].kg;
    }
    int otv=0;
        sort (mas, mas+n);
        for (int q=0; q<n; q++)
        {
            while (mas[q].kg>=k&&mas[q].kol<3)
            {
                mas[q].kg-=k;
                mas[q].kol++;
            }
            otv+=mas[q].kg;
        }
    cout << otv;
    return 0;
}