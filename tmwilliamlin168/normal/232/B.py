n,m,k=map(int,input().split())
M=int(1e9+7)

N=n*n
iv=[0]*(N+1)
iv[1]=1
for i in range(2, N+1):
    iv[i]=M-M//i*iv[M%i]%M
f1=[1]*(N+1)
for i in range(1, N+1):
    f1[i]=f1[i-1]*i%M
f2=[1]*(N+1)
for i in range(1, N+1):
    f2[i]=f2[i-1]*iv[i]%M
left=m%n
#m/n+1, m/n
def powM(b, p):
    r=1
    while p>0:
        if p%2>0:
            r=r*b%M
        b=b*b%M
        p//=2
    return r
c=[[powM(f1[n]*f2[j]%M*f2[n-j]%M, m//n+i) for j in range(n+1)] for i in range(2)]
#print(c)
dp=[[0]*(k+1) for i in range(n+1)]
dp[0][0]=1
for i in range(n):
    for j in range(k+1):
        #prune
        if j>i*n or j<k-(n-i)*n:
            continue
        for l in range(min(n, k-j)+1):
            # i,j -> i+1,j+l
            dp[i+1][j+l]=(dp[i+1][j+l]+c[i<left][l]*dp[i][j])%M
print(dp[n][k])