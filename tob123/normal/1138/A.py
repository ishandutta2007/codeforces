from sys import stdin

n = int(input())
last = -1
cntL = 0
cntCur = 0
best = 0

for cur in stdin.readline().split():
  if cur == last:
    cntCur += 1
    best = max(best, min(cntCur, cntL))
  else:
    cntL, cntCur = cntCur, 1
    last = cur
    best = max(best, min(cntCur, cntL))

print(best*2)