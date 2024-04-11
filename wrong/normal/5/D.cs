using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeForces
{
    static class Reader
    {
        public static int NextInt()
        {
            int ret = 0;
            char c;

            while (!char.IsDigit(c = (char)Console.Read())) { }
            do
            {
                ret = ret * 10 + c - '0';
            } while (char.IsDigit(c = (char)Console.Read()));

            return ret;
        }

        public static double NextDouble()
        {
            double ret = 0;
            char c;

            while (!char.IsDigit(c = (char)Console.Read())) { }
            do
            {
                ret = ret * 10 + c - '0';
            } while (char.IsDigit(c = (char)Console.Read()));
            if (c != '.') return ret;

            double p10 = 0.1;
            while (char.IsDigit(c = (char)Console.Read()))
            {
                ret += p10 * (c - '0');
            }

            return ret;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            double a, v, l, d, w;

            a = Reader.NextDouble();
            v = Reader.NextDouble();
            l = Reader.NextDouble();
            d = Reader.NextDouble();
            w = Math.Min(v, Reader.NextDouble());

            double speed_w_time = w / a;
            double speed_v_time = v / a;
            if (a * speed_w_time * speed_w_time / 2 >= d)
            {
                if (a * speed_v_time * speed_v_time / 2 >= l)
                    Console.WriteLine("{0,8:F8}", Math.Sqrt(2 * l / a));
                else
                {
                    double rem = l - (a * speed_v_time * speed_v_time / 2);
                    Console.WriteLine("{0,8:F8}", speed_v_time + rem / v);
                }
            }
            else
            {
                double speed_v_dist = a * speed_v_time * speed_v_time / 2;
                double speed_vtow_time = (v - w) / a;
                double speed_vtow_dist = v * speed_vtow_time + (-a) * speed_vtow_time * speed_vtow_time / 2;
                double sign_time;

                if (speed_v_dist + speed_vtow_dist <= d)
                {
                    double rem = d - speed_vtow_dist - speed_v_dist;
                    sign_time = speed_v_time + rem / v + speed_vtow_time;
                }
                else
                {
                    double lo = w, hi = v;
                    for (int loop = 0; loop < 64; ++loop)
                    {
                        double mid = (hi + lo) / 2;
                        double speed_mid_time = mid / a;
                        double speed_mid_dist = a * speed_mid_time * speed_mid_time / 2;
                        double speed_mtow_time = (mid - w) / a;
                        double speed_mtow_dist = mid * speed_mtow_time + (-a) * speed_mtow_time * speed_mtow_time / 2;

                        if (speed_mid_dist + speed_mtow_dist <= d)
                            lo = mid;
                        else
                            hi = mid;
                    }

                    double speed_lo_time = lo / a;
                    double speed_ltow_time = (lo - w) / a;
                    sign_time = speed_lo_time + speed_ltow_time;
                }

                double speed_wtov_time = (v - w) / a;
                double speed_wtov_dist = w * speed_wtov_time + a * speed_wtov_time * speed_wtov_time / 2;
                if (speed_wtov_dist >= l - d)
                {
                    // (a/2)t^2 + wt - l + d = 0
                    double A = a / 2, B = w, C = d - l;
                    double D = B * B - 4 * A * C;
                    double t1, t2;

                    t1 = ((-B) + Math.Sqrt(D)) / (2 * A);
                    t2 = ((-B) - Math.Sqrt(D)) / (2 * A);

                    if (t2 >= 0) t1 = t2;
                    Console.WriteLine("{0,8:F8}", sign_time + t1);
                }
                else
                {
                    double rem = l - d - speed_wtov_dist;
                    Console.WriteLine("{0,8:F8}", sign_time + speed_wtov_time + rem / v);
                }
            }
        }
    }
}