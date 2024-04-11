n=int(raw_input())
rk=[int(k) for k in raw_input().split(" ")]

arele=[1 if (rk[k]-rk[k-1])*(rk[k]-rk[k+1])>0 else 0 for k in range(1,n-1)]

print sum(arele)