n = int(input())
arr = []
on = 1
while n>2*on:
  n-=on
  arr.append(on)
  on+=1
arr.append(n)
print(len(arr))
print(' '.join(map(str,arr)))