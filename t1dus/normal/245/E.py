s = input()
mx = 0
mn = 0
cur = 0
for i in s:
  if i == '+':
    cur += 1
  else:
    cur -= 1
  mx = max(mx,cur)
  mn = min(mn,cur)
print(abs(mx-mn))