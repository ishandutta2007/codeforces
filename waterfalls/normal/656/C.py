s = input()
res = 0
for c in s:
  if c.isalpha():
    if c.isupper():
      res+=ord(c)-ord('@')
    else:
      res-=ord(c)-ord('`')
print(res)