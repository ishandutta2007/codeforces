uses math;
var x,y,ans,t:longint;
    now,next:array[1..3] of longint;
begin
  readln(x,y);
  ans:=0;
  now[1]:=y;now[2]:=y;now[3]:=y;t:=1;
  next[1]:=2;next[2]:=3;next[3]:=1;
  while not((now[1]=x) and (now[2]=x) and (now[3]=x)) do
  begin
    inc(ans);
    now[t]:=min(x,now[1]+now[2]+now[3]-now[t]-1);
    t:=next[t];
  end;
  writeln(ans);
end.