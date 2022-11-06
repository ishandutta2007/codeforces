n=int(raw_input())
#a=[int(k) for k in raw_input().split(" ")]

ts0=[0,1023]#range(1024)#
for k in range(n):
    ope,c=raw_input().split(" ")
    c=int(c)
    for jj in range(len(ts0)):
        if ope=="&":
            ts0[jj]&=c
        elif ope=="|":
            ts0[jj]|=c
        elif ope=="^":
            ts0[jj]^=c

ope1=1023
ope2=0
ope3=0

i=1
types=[0]*10
for j in range(10):
    if ts0[0]&i:
        types[j]+=2
    if ts0[-1]&i:
        types[j]+=1
    if types[j]==0:
        ope1-=i
    elif types[j]==2:
        ope2+=i
    elif types[j]==3:
        ope3+=i
    i*=2

print 3
print "&",ope1
print "^",ope2
print "|",ope3

##test : 23 min into je construis, 7 min to build test 
#ts1=range(1024) #must be initialized like ts0
#for k in range(len(ts1)):
#    ts1[k]=(((ts1[k]&ope1)^ope2)|ope3)
#    if ts1[k]!=ts0[k]:
#        print k,ts1[k],ts0[k]