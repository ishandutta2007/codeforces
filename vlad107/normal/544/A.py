n=input()
s=raw_input()
c,r=[],''
for i in s:
    if len(c)<n and i not in c:
        c+=[i]
        r+='\n'
    r+=i
print(["YES"+r,"NO"][len(c)<n])