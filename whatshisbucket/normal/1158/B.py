n,k=map(int,input().split())
diff=(n-k)//2
if diff==0:
    print("1"*n)
else:
    rep="1"*diff+"0"
    long=rep*(200000//diff+1)
    print(long[:n])