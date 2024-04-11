a,b=map(int,input().split())
d=[]
for i in range(0,a):
    s=str(input())
    d.append([])
    for t in s:
        d[i].append(t)
m2=0
m1=0
for i in range(0,len(d)):
    t=0
    low=0
    while t==0 and low<len(d[0]):
        if(d[i][low]=='W'):
            low+=1
        else:
            t=1
    up=(len(d[i])-1)
    t=0
    while t==0 and up>=0:
        if(d[i][up]=='W'):
            up-=1
        else:
            t=1
    if(t==1):
        m2=((low+up)/2)+1
for i in range(0,len(d[0])):
    t=0
    low=0
    while t==0 and low<len(d):
        if(d[low][i]=='W'):
            low+=1
        else:
            t=1
    up=(len(d)-1)
    t=0
    while t==0 and up>=0:
        if(d[up][i]=='W'):
            up-=1
        else:
            t=1
    if(t==1):
        m1=((low+up)/2)+1
print(int(m1),int(m2))