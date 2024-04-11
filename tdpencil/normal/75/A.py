n = int(input())
x = int(input())
a = ""
b = ""
c = ""
d = ""
e = ""
f = ""
for i in str(n):
    if i!="0":
        a+=i
for i in str(x):
    if i!="0":
        b+=i
f = n+x
for i in str(f):
    if i!="0":
        c+=i
if (int(a) + int(b)) == int(c):
    print("YES")
else:
    print("NO")