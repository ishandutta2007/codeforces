n=int(input())
s=input()
starlen=0
boo=s[0]
for char in s:
    if char==boo:
        starlen+=1
    else:
        break
boop=s[-1]
endlen=0
for char in s[::-1]:
    if char==boop:
        endlen+=1
    else:
        break
if boo!=boop:
    print(starlen+endlen+1)
else:
    if starlen==len(s):
        print((starlen*(starlen+1)//2)%998244353)
    else:
        print(((starlen+1)*(endlen+1))%998244353)