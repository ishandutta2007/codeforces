def mini(s):
    x = len(s)
    if x%2==1:
        return s
    x//=2
    a = mini(s[0:x])
    b = mini(s[x::])
    return a+b if a<b else b+a
a,b = input(),input()
print("YES" if mini(a)==mini(b) else "NO")