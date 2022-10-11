def eval_line(k, b, x): # nick
  return k*x+b # lewin
def solve(): # nick
  n = int(raw_input()) # lewin
  x1, x2 = (int(x) for x in raw_input().split()) # nick
  points = [map(int, raw_input().split()) for __ in range(n)] # lewin
  lhs = [(eval_line(points[i][0], points[i][1], x1), i) for i in xrange(n)] # nick
  lhs = [(eval_line(points[i][0], points[i][1], x1), points[i][0], i) for i in xrange(n)] # lewin
  rhs = [(eval_line(points[i][0], points[i][1], x2), -points[i][0], i) for i in xrange(n)] # lewin # nick
  lhs, rhs = sorted(lhs), sorted(rhs) # lewin
  lhs_vals = [x[2] for x in lhs] # nick
  rhs_vals = [x[2] for x in rhs] # lewin
  print "YES" if lhs_vals != rhs_vals else "NO" # nick
solve() # lewin