{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b,c,sx,sy,t1,t2,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,tmp: int64;
  ok: boolean;
  qq,tt,r: longint;

function cont(x1,y1,x2,y2,x3,y3:int64):boolean;
begin
  if (x3 < x1) and (x3 < x2) or (x3 > x1) and (x3 > x2) then cont:=False else
  if (y3 < y1) and (y3 < y2) or (y3 > y1) and (y3 > y2) then cont:=False else
  if (x1 = x3) and (y1 = y3) or (x2 = x3) and (y2 = y3) then cont:=False else
  begin
    a:=y2-y1;
    b:=x1-x2;
    c:=-a*x1-b*y1;
    if a*x3+b*y3+c = 0 then cont:=True
    else cont:=False;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  for qq:=1 to tt do
  begin
    read(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6);
    ok:=False;
    for r:=1 to 3 do
    begin
      if (x1 = x4) and (y1 = y4) then
      begin
        tmp:=x3; x3:=x4; x4:=tmp;
        tmp:=y3; y3:=y4; y4:=tmp;
      end;
      if (x2 = x3) and (y2 = y3) then
      begin
        tmp:=x1; x1:=x2; x2:=tmp;
        tmp:=y1; y1:=y2; y2:=tmp;
      end;
      if (x2 = x4) and (y2 = y4) then
      begin
        tmp:=x3; x3:=x4; x4:=tmp;
        tmp:=y3; y3:=y4; y4:=tmp;
        tmp:=x1; x1:=x2; x2:=tmp;
        tmp:=y1; y1:=y2; y2:=tmp;
      end;
      if (x1 = x3) and (y1 = y3) then
      begin
        sx:=(x2-x1)*(x4-x3);
        sy:=(y2-y1)*(y4-y3);
        if sx+sy >= 0 then
        begin
          if cont(x1,y1,x2,y2,x6,y6) and cont(x3,y3,x4,y4,x5,y5) then
          begin
            tmp:=x5; x5:=x6; x6:=tmp;
            tmp:=y5; y5:=y6; y6:=tmp;
          end;
          if cont(x1,y1,x2,y2,x5,y5) and cont(x3,y3,x4,y4,x6,y6) then
          begin
            if x1 <> x2 then
            begin
              t1:=abs(x1-x5);
              t2:=abs(x2-x5);
            end else
            begin
              t1:=abs(y1-y5);
              t2:=abs(y2-y5);
            end;
            if (t1*4 >= t2) and (t2*4 >= t1) then
            begin
              if x3 <> x4 then
              begin
                t1:=abs(x3-x6);
                t2:=abs(x4-x6);
              end else
              begin
                t1:=abs(y3-y6);
                t2:=abs(y4-y6);
              end;
              if (t1*4 >= t2) and (t2*4 >= t1) then
              begin
                ok:=True;
                break;
              end;
            end;
          end;
        end;
      end;
      tmp:=x1; x1:=x3; x3:=x5; x5:=tmp;
      tmp:=y1; y1:=y3; y3:=y5; y5:=tmp;
      tmp:=x2; x2:=x4; x4:=x6; x6:=tmp;
      tmp:=y2; y2:=y4; y4:=y6; y6:=tmp;
    end;
    if ok then writeln('YES')
    else writeln('NO');
  end;
  close(input);
  close(output);
end.