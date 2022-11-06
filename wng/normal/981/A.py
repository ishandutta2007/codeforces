#[int(k) for k in raw_input().split(" ")]

def ispal(s):
    n=len(s)
    for i in range(n):
        if s[i]!=s[n-1-i]:
            return False
        if i>n-1-i:
            return True
    return True

s=raw_input()

n=len(s)

l=n

while l:
    isok=False
    for i in range(n-l+1):
        if not ispal(s[i:i+l]):
            isok=True
            break
    if isok:
        break
    l-=1

print l