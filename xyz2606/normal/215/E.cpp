#include<cstring>
#include<cstdio>
long long l, r, a[111], cnt[111], f[111];
bool chk[111];
long long bin(int l, int r)
{
    long long rtn = 0;
    for(int i = l; i > r; i--) rtn = rtn * 2 + a[i];
    return rtn;
}
long long gets(long long n)
{
    if(n == 0) return 0;
    long long x = n, ans = 0, l=0;
    while(x)
    {
        a[++l] = x & 1;
        x /= 2;
    }
    for(int i = l; i >= 1; i--) if(l % i == 0)
    {
        chk[i] = true;
        for(int j = l-i; j > 0; j -= i)
        {
            if(bin(j, j-i)  < bin(l, l-i)) 
            {
                chk[i] = false; break;
            }else if(bin(j, j-i) > bin(l, l-i))
            {
                chk[i] = true; break;
            }
        }
    }
    for(int i = 1; i <= 60; i++)
    {
        for(int j = 2; j*i < l; j++)
        {
                ans += f[i];
        }
        if(l % i != 0 or l == i) continue;
        long long ans1 = (bin(l, l-i) - ((1ll<<(i-1))-1));
        if(chk[i] == false) ans1--;
        for(int k = i-1; k >= 1; k--) 
        {
            cnt[k] = 0;
        }
        for(int k = i-1; k >= 1; k--) if(i % k == 0)
        {
            ans1 = ans1 + (-1 - cnt[k]) * (bin(l, l-k) - ((1ll<<(k-1))-1));
            if(chk[k] == false) ans1 -= -1 - cnt[k];
            for(int l = k - 1; l >= 1; l--) if(k % l == 0)
                cnt[l] += -1 - cnt[k];
        }
        ans += ans1;
    }
    return ans;
}
int main()
{   
    for(int i = 1; i <= 60; i++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j++) f[i] *= 2;
        for(int j = 1; j < i; j++) if(i % j == 0) f[i] -= f[j];
    }
    scanf("%I64d%I64d", &l, &r);
    printf("%I64d\n", gets(r) - gets(l-1));
    fclose(stdin);
    return 0;
}