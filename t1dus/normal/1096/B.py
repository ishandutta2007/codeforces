n = int(input())
s = input()
preind = 0
sufind = n-1
for i in range(n):
    if s[i] != s[0]:
        preind = i;
        break
for i in range(n-1,-1,-1):
    if s[i] != s[n-1]:
        sufind = i;
        break
# print(preind,sufind)
if s[0] == s[n-1]:
    print(((preind+1)*(n-sufind))%998244353)
else:
    print((preind+n-sufind)%998244353)