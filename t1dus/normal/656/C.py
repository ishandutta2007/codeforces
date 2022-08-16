s = input()
ans = 0
abc = 'abcdefghijklmnopqrstuvwxyz'

val = {}
for i in range(len(abc)):
    val[abc[i]] = i+1
    
for i in s:
    if i == i.upper():
        try:
            ans += val[i.lower()]
        except:
            pass
    elif i == i.lower():
        ans -= val[i]

print(ans)