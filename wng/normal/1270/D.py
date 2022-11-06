

from sys import stdout

n,k=[int(k) for k in input().strip().split(" ")]
stl=list(range(1,k+1))

if k==1:
    print("! 1")
    exit()

print(" ".join(["?"]+[str(i) for i in stl]))
stdout.flush()
a={}
j,v=[int(k) for k in input().strip().split(" ")]
a[j]=v

#print(a)
pivot=1
while pivot==j:
    pivot+=1

cotes=[0]*(n+1)
cotes[pivot]=1
for i in range(k+1,n+1):
    tc=[ii if ii!= pivot else i for ii in stl]
    print(" ".join(["?"]+[str(ii) for ii in tc]))
    stdout.flush()
    jj,vv=[int(k) for k in input().strip().split(" ")]
    a[jj]=vv
    if (j==jj):
        cotes[i]=cotes[pivot]
    else:
        cotes[i]=-cotes[pivot]

newpivot=n

for i in range(1,k+1):
    if i!=j and i!=pivot:
        tc=[ii if ii!=i else newpivot for ii in stl]
        print(" ".join(["?"]+[str(ii) for ii in tc]))
        stdout.flush()
        jj,vv=[int(k) for k in input().strip().split(" ")]
        a[jj]=vv
        if (j==jj):
            cotes[i]=cotes[newpivot]
        else:
            cotes[i]=-cotes[newpivot]

if len(a)==1:
    tc=[ii for ii in range(1,k+2) if ii!=j]
    print(" ".join(["?"]+[str(ii) for ii in tc]))
    stdout.flush()
    jj,vv=[int(k) for k in input().strip().split(" ")]
    a[jj]=vv

realcotes=[0]*(n+1)
for kk in a:
    if kk!=j:
        realcotes[kk]=1 if a[kk]>a[j] else -1
        for ii in range(1,n+1):
            realcotes[ii]=cotes[ii]*cotes[kk]*realcotes[kk]
        break

m=1
for i in range(1,k+1):
    if realcotes[i]<0:
        m+=1
print("! {}".format(m))
stdout.flush()