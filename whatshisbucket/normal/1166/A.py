n=int(input())
alphabet="abcdefghijklmnopqrstuvwxyz"
count={}
for char in alphabet:
    count[char]=0
for i in range(n):
    name=input()
    count[name[0]]+=1
sumi=0
for guy in count:
    a=count[guy]
    b=a//2
    c=a-b
    sumi+=b*(b-1)//2+c*(c-1)//2
print(sumi)