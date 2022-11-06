n=int(raw_input())
if n%2:
    a=range(n)
    b=range(1,n)+[0]
    c=[(a[i]+b[i])%n for i in range(n)]
    
    print " ".join([str(k) for k in a])
    print " ".join([str(k) for k in b])
    print " ".join([str(k) for k in c])
else:
    print -1