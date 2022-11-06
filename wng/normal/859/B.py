n=int(raw_input())
res=2*n+2

k=2
while (k-1)*(k-1)<=n:
    c=(n-1)/k+1
    res=min(res,2*(c+k))
    k+=1
    
print res