from sys import stdin, stdout

n = int(stdin.readline())
a = [int(x) for x in stdin.readline().strip()]
c = [int(x) for x in stdin.readline().strip()]
ind = [[],[],[],[]]

for i in range(len(a)):
  ind[2*a[i]+c[i]].append(i+1)

cnt = []
r = []

for i in range(n//2 + 1): #numbers in set 1 with first bit set
  for j in range(i+1): # number of 10 in first set
    if j > len(ind[2]):
      continue;
    if i-j > len(ind[3]):
      continue;
    cnt = [len(x) for x in ind]
    cnt[2] -= j
    cnt[3] += - i + j
    cnt1soll = i - cnt[3]
    cnt0soll = n//2 - i - cnt[2]
    if cnt1soll >= 0 and cnt1soll <= cnt[1] and cnt0soll >= 0 and cnt0soll <= cnt[0]:
      #print(cnt)
      #print('i: ', i, ', j: ', j)
      for x in range(j):
        r.append(ind[2][x])
      for x in range(i-j):
        r.append(ind[3][x])
      for x in range(cnt[1]-cnt1soll):
        r.append(ind[1][x])
      for x in range(cnt[0]-cnt0soll):
        r.append(ind[0][x])
      break;
  else:
    continue;
  break;
else:
  r = [-1]

r = [str(x) for x in r]
r.append('\n')
stdout.write(" ".join(r))