b = 0
w = 0
for i in 1..8 do
  str = gets
  for j in 0..str.length-1 do
    case str[j]
    when 'Q'
      w+=9
    when 'R'
      w+=5
    when 'B'
      w+=3
    when 'N'
      w+=3
    when 'P'
      w+=1
    when 'q'
      b+=9
    when 'r'
      b+=5
    when 'b'
      b+=3
    when 'n'
      b+=3
    when 'p'
      b+=1
    else
      w+=0
      b+=0
    end
  end
end
if b>w then
  print "Black"
end
if w>b then
  print "White"
end
if w==b then
  print "Draw"
end