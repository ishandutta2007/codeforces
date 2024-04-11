n,m=[int(k) for k in input().strip().split(" ")]
s=input().split(" ")
t=input().split(" ")
q=int(input())
for i in range(q):
    a=int(input())-1
    print(s[a%n]+t[a%m])