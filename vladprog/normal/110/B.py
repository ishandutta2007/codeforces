n=int(input())
s='abcd'*(n//4)
n=n%4
if n>=1:
    s+='a'
if n>=2:
    s+='b'
if n>=3:
    s+='c'
print(s)