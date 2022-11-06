import sys

x1=0
x2=0

for i in range(14):
    if i%2:
        x1+=1<<i
    else:
        x2+=1<<i

l1=[]
l2=[]
res=0
for i in range(100):
    a=bin(i)[2:]
    if len(a)<7:
        a="0"*(7-len(a))+a
    l2+=[int("".join([k+"1" for k in a]),2)]
    l1+=[int("".join(["1"+k for k in a]),2)]

#print(x1,x2)
#print(bin(x1),bin(l1[0]))
print("? "+" ".join([str(k) for k in l1]))
sys.stdout.flush()
rep=int(input())
res+=(rep&x1)^x1
#print("yeah :",rep&x1,(rep&x1)^x1)
print("? "+" ".join([str(k) for k in l2]))
sys.stdout.flush()
rep=int(input())
res+=(rep&x2)^x2
#print("yeah :",(rep&x2)^x2)
print("! {}".format(res))
sys.stdout.flush()