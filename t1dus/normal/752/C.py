def anti(a,b):
    if a == 'L' and b == 'R':
        return False
    elif a == 'U' and b == 'D':
        return False
    elif a == 'R' and b == 'L':
        return False
    elif a == 'D' and b == 'U':
        return False    
    return True
    
n = int(input())
s = input()
i = 1
a = s[0]
b = ''
ans = 1
while i < n:
    if s[i] == a or s[i] == b:
        pass
    elif b == '' and anti(a,s[i]):
        b = s[i]
    else:
        a = s[i]
        b = ''
        ans += 1
    i += 1    
print(ans)