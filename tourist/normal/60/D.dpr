{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = round(1e7);
var
  n,i,e,ans,j,qx,qy,qz,m,q,w,lg,rg,aa,bb: longint;
  was: array [0..co+10] of boolean;
  last,x,ss,ff,pred: array [0..co+10] of longint;

procedure add(q,w:longint);
begin
  inc(m);
  ss[m]:=q;
  ff[m]:=w;
  pred[m]:=last[q];
  last[q]:=m;
  inc(m);
  ss[m]:=w;
  ff[m]:=q;
  pred[m]:=last[w];
  last[w]:=m;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  fillchar(last,sizeof(last),0);
  m:=0;
  for q:=1 to co div 2 do
  begin
    lg:=1; rg:=q-1;
    if int64(q)*q > co then lg:=round(sqrt(1.0*(int64(q)*q-co)));
    if co div 2 div q < rg then rg:=co div 2 div q;
    for w:=lg to rg do
    begin
      aa:=q; bb:=w;
      while (aa > 0) and (bb > 0) do
        if aa > bb then aa:=aa mod bb
        else bb:=bb mod aa;
      if (aa+bb = 1) and ((q+w) and 1 = 1) then
      begin
        qx:=int64(q)*q-int64(w)*w;
        qy:=2*q*w;
        qz:=int64(q)*q+int64(w)*w;
        if (qx <= co) and (qy <= co) then add(qx,qy);
        if (qx <= co) and (qz <= co) then add(qx,qz);
        if (qy <= co) and (qz <= co) then add(qy,qz);
      end;
    end;
  end;
  randseed:=8753;
  fillchar(was,sizeof(was),True);
  read(n);
  for i:=1 to n do
  begin
    read(q);
    was[q]:=False;
  end;
  ans:=0;
  for q:=1 to co do
    if not was[q] then
    begin
      inc(ans);
      i:=1; e:=1;
      x[1]:=q;
      was[q]:=True;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if not was[ff[j]] then
          begin
            inc(e);
            x[e]:=ff[j];
            was[x[e]]:=True;
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
    end;
  writeln(ans);
  close(input);
  close(output);
end.