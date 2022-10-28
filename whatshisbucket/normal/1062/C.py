n,q=map(int,raw_input().split())
powers=[1]+[0]*n
for i in xrange(n):
    powers[i+1]=(2*powers[i])%1000000007
s=raw_input()
zeroes=[0]*(n+1)
for i in xrange(n):
    zeroes[i+1]=zeroes[i]+1-int(s[i])
for i in xrange(q):
    l,r=map(int,raw_input().split())
    guy=powers[r-l+1]-powers[zeroes[r]-zeroes[l-1]]
    guy%=1000000007
    print(guy)