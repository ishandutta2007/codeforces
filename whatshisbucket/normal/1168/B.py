s=input()
n=len(s)
sml=(n*(n+1))//2
for i in range(8):
    sml-=max(n-i,0)
good3=set()
good4=set()
good5=set()
good6=set()
good7=set()
for i in range(n-2):
    if s[i]==s[i+1]==s[i+2]:
        good3.add(i)
        sml+=1
for i in range(n-3):
    if i in good3 or i+1 in good3:
        good4.add(i)
        sml+=1
for i in range(n-4):
    if i in good4 or i+1 in good4 or s[i]==s[i+2]==s[i+4]:
        good5.add(i)
        sml+=1
for i in range(n-5):
    if i in good5 or i+1 in good5:
        good6.add(i)
        sml+=1
for i in range(n-6):
    if i in good6 or i+1 in good6 or s[i]==s[i+3]==s[i+6]:
        good7.add(i)
        sml+=1
for i in range(n-7):
    if i in good7 or i+1 in good7:
        sml+=1
print(sml)