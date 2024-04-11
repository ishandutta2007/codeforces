import sys

outp=[0]*6

outp[0] = "+------------------------+";
outp[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
outp[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
outp[3] = "|#.......................|";
outp[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
outp[5] = "+------------------------+";
outq = [0]*6

for b in range(6):
  outq[b]=list(outp[b])

k=int(raw_input())

delta = 0
for zz in range(k):
  for ind in range(90):
    for bus in range(6):
      delta = 0
      if outq[bus][ind]=='#':
        outq[bus][ind]='O'
        delta = 1
        break
    if delta == 1:
      break

for bus in range(6):
  for c in outq[bus]:
    sys.stdout.write(c)
  print