n,m=map(int,input().split())
a=input()
b=input()
countlist=[]
man=0
if len(a)<len(b):
    a="0"*(len(b)-len(a))+a
if len(b)<len(a):
    b="0"*(len(a)-len(b))+b
for i in range(len(b)):
    if b[i]=="1":
        man+=1
    countlist.append(man)
power=1
sum=0
for i in range(len(a)):
    if a[-i-1]=="1":
        sum+=power*countlist[-i-1]
    power=(2*power)%998244353
print(sum%998244353)