a,b,c=map(int,raw_input().split())
print str((a+b+c%2*b)*10**500/b).find(str(c))