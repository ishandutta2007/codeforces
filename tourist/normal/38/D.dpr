{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,ans,j: longint;
  ok: boolean;
  xx,yy,cc,tmp: int64;
  a,x1,y1,x2,y2: array [0..1010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  ans:=0;
  for i:=1 to n do
  begin
    read(x1[i],y1[i],x2[i],y2[i]);
    if x1[i] > x2[i] then begin tmp:=x1[i]; x1[i]:=x2[i]; x2[i]:=tmp; end;
    if y1[i] > y2[i] then begin tmp:=y1[i]; y1[i]:=y2[i]; y2[i]:=tmp; end;
    a[i]:=x2[i]-x1[i];
    ok:=True;
    xx:=0; yy:=0;
    cc:=0;
    for j:=i downto 2 do
    begin
      xx:=xx+a[j]*a[j]*a[j]*(x1[j]+x2[j]);
      yy:=yy+a[j]*a[j]*a[j]*(y1[j]+y2[j]);
      cc:=cc+a[j]*a[j]*a[j]*2;
      if (xx >= x1[j-1]*cc) and (xx <= x2[j-1]*cc) and (yy >= y1[j-1]*cc) and (yy <= y2[j-1]*cc) then else
      begin
        ok:=False;
        break;
      end;
    end;
    if not ok then break;
    inc(ans);
  end;
  writeln(ans);
  close(input);
  close(output);
end.