n = int(input())
l = input().strip()
r = input().strip()

cntl = [[] for x in range(27)]
cntr = [[] for x in range(27)]

for i in range(n):
  if l[i] == '?':
    cntl[26].append(i)
  else:
    cntl[ord(l[i])-ord('a')].append(i)

for i in range(n):
  if r[i] == '?':
    cntr[26].append(i)
  else:
    cntr[ord(r[i])-ord('a')].append(i)

ovrL = []
ovrR = []
r = []

for i in range(26):
  to = min(len(cntl[i]), len(cntr[i]))
  for j in range(min(len(cntl[i]), len(cntr[i]))):
    r.append((cntl[i][j], cntr[i][j]))
  ovrL[len(ovrL):] = cntl[i][to:]
  ovrR[len(ovrR):] = cntr[i][to:]

for i in range(min(len(ovrL), len(cntr[26]))):
  r.append((ovrL[i], cntr[26].pop()))

for i in range(min(len(ovrR), len(cntl[26]))):
  r.append((cntl[26].pop(), ovrR[i]))

for i in range(min(len(cntl[26]), len(cntr[26]))):
  r.append((cntl[26][i], cntr[26][i]))

r = [str(a+1) + " " + str(b+1) for a,b in r]
print(len(r))
print("\n".join(r))