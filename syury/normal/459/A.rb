

class Point
  def initialize(x_c,y_c)
    @x_coord=x_c
    @y_coord=y_c
  end
  def x
    return @x_coord
  end
  def y
    return @y_coord
  end
end

a,b,c,d = gets.split(" ").map {|x| x.to_i}

p1=Point.new(a,b)
p2=Point.new(c,d)

if p1.x==p2.x
  d = (p1.y-p2.y).abs
  print "#{p1.x+d} #{p1.y} #{p2.x+d} #{p2.y}"
  exit
end

if p1.y==p2.y
  d = (p1.x-p2.x).abs
  print "#{p1.x} #{p1.y+d} #{p2.x} #{p2.y+d}"
  exit
end

if (p1.x-p2.x).abs!=(p1.y-p2.y).abs
  print "-1"
  exit
end

print "#{p1.x} #{p2.y} #{p2.x} #{p1.y}"