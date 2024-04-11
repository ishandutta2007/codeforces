import math

def fact(nn):
    p=2
    df={}
    while nn%2==0:
        if 2 not in df:
            df[2]=0
        df[2]+=1
        nn/=2
    p=3
    s=math.sqrt(nn)+1
    while p<s:
        while nn%p==0:
            if p not in df:
                df[p]=0
            df[p]+=1
            nn/=p
            s=math.sqrt(nn)+1
        p+=2
    if nn>1:
        df[nn]=1
    return df

n,k =[int(i) for i in raw_input().split(" ")]
a=[int(i) for i in raw_input().split(" ")]

fk=fact(k)
nbf=len(fk)
afacts=[0]*n
sfacts=[0]*n
sfacts[-1]=[0]*nbf
fs=fk.keys()
gg=[fk[i] for i in fs]

for i in range(n):
    afacts[i]=[0]*nbf
    sfacts[i]=[0]*nbf
    ni=a[i]
    for j in range(nbf):
        nbfj=0
        while nbfj<fk[fs[j]] and ni%fs[j]==0:
            ni/=fs[j]
            nbfj+=1
        afacts[i][j]=nbfj
        sfacts[i][j]=sfacts[i-1][j]+nbfj

#OK now we want all the sfacts[n-y]-sfacts[x]>gg
x=0
y=n-1
vires=[0]*nbf
res=0
while x<n:
    virend=sfacts[n-y-1]
    OK=True
    for i in range(nbf):
        if virend[i]-vires[i]<gg[i]:
            OK=False
            break
    while not OK and y>0:
        y-=1
        OK=True
        virend=sfacts[n-y-1]
        for i in range(nbf):
            if virend[i]-vires[i]<gg[i]:
                OK=False
                break
   # print x,y,OK,y+1
    vires=sfacts[x]
    if not OK:
        break
  #print y+1
    res+=y+1
    x+=1
    y=min(y,n-x-1)

print res