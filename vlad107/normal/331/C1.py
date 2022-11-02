n=int(input())
f=0
while (n>0):
    f+=1
    n-=max(set(map(int,str(n))))
print f