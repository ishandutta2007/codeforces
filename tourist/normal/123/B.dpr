{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans,lg,rg,ca,cb,a,b,x1,y1,x2,y2,xa,ya,xb,yb: int64;

function up(x,y:int64):int64;
var
  u: int64;
begin
  u:=x div y;
  while (u-1)*y > x do dec(u);
  while u*y <= x do inc(u);
  up:=u;
end;

function down(x,y:int64):int64;
var
  u: int64;
begin
  u:=x div y;
  while u*y >= x do dec(u);
  while (u+1)*y < x do inc(u);
  down:=u;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,x1,y1,x2,y2);
  xa:=x1+y1; ya:=x1-y1;
  xb:=x2+y2; yb:=x2-y2;
  if (a = 1) or (b = 1) then ans:=(abs(x1-x2)+abs(y1-y2)) div 2 else
  begin
    if xa < xb then
    begin
      lg:=up(xa,2*a);
      rg:=down(xb,2*a);
    end else
    begin
      lg:=up(xb,2*a);
      rg:=down(xa,2*a);
    end;
    ca:=rg-lg+1;
    if ya < yb then
    begin
      lg:=up(ya,2*b);
      rg:=down(yb,2*b);
    end else
    begin
      lg:=up(yb,2*b);
      rg:=down(ya,2*b);
    end;
    cb:=rg-lg+1;
    if ca > cb then ans:=ca
    else ans:=cb;
  end;
  writeln(ans);
  close(input);
  close(output);
end.