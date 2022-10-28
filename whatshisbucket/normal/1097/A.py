s=input()
v=input().split()
a=[i[0] for i in v]
b=[i[1] for i in v]
if s[0] in a or s[1] in b:
    print("YES")
else:
    print("NO")