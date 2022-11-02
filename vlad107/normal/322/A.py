n,m=map(int,raw_input().split())
print "\n".join([str(n+m-1)]+["1 "+str(i+1) for i in range(m)]+[str(i+1)+" 1" for i in range(1,n)])